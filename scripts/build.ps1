#Requires -Version 7.0
param(
    [string]$WindhawkPath = "$env:ProgramFiles\Windhawk",
    [switch]$RunTests
)
$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
$config=Get-Content -Raw -LiteralPath (Join-Path $WindhawkPath 'windhawk.ini')
$engineMatch=[regex]::Match($config,'(?m)^EnginePath=(.+)\r?$')
if(-not $engineMatch.Success){throw 'EnginePath not found in windhawk.ini'}
$enginePath=$engineMatch.Groups[1].Value.Trim()
if(-not [IO.Path]::IsPathRooted($enginePath)){$enginePath=Join-Path $WindhawkPath $enginePath}
$compiler=Join-Path $WindhawkPath 'Compiler\bin\clang++.exe'
if(-not(Test-Path -LiteralPath $compiler)){throw 'Windhawk compiler is not installed at the specified location.'}
$output=Join-Path $root 'build'
New-Item -ItemType Directory -Path $output -Force | Out-Null
$common=@('-std=c++23','-O2','-DUNICODE','-D_UNICODE','-DWINVER=0x0A00','-D_WIN32_WINNT=0x0A00','-D_WIN32_IE=0x0A00','-DNTDDI_VERSION=0x0A000008','-D__USE_MINGW_ANSI_STDIO=0','-DWH_MOD','-include','windhawk_api.h')
$mods=Get-Content -Raw -LiteralPath (Join-Path $root 'mods.json') | ConvertFrom-Json
foreach($mod in $mods){
    foreach($arch in $mod.architectures){
        $target=switch($arch){'32'{'i686-w64-mingw32'} '64'{'x86_64-w64-mingw32'} default{throw "Unsupported architecture: $arch"}}
        $dir=Join-Path $output $arch
        New-Item -ItemType Directory -Path $dir -Force | Out-Null
        $dll=Join-Path $dir ('local@'+$mod.id+'_'+$mod.version+'.dll')
        $defines=@(('-DWH_MOD_ID=L"local@'+$mod.id+'"'),('-DWH_MOD_VERSION=L"'+$mod.version+'"'))
        $warnings=@('-Wall','-Wextra','-Wno-unused-parameter','-Wno-missing-field-initializers')
        if($mod.id -eq 'maycon-large-folder-icons'){$warnings+= '-Werror'}
        $arguments=$common+$defines+$warnings+@('-shared','-Wl,--export-all-symbols','-target',$target,(Join-Path $enginePath ($arch+'\windhawk.lib')),(Join-Path $root $mod.source))+$mod.libraries+@('-o',$dll)
        & $compiler @arguments
        if($LASTEXITCODE -ne 0){throw ('Build failed: '+$mod.id+' / '+$arch)}
        Write-Output ('PASS build: '+$mod.id+' / '+$arch)
    }
}
if($RunTests){
    $exe=Join-Path $output 'test-settings.exe'
    $argsTest=$common+@('-DWH_EDITING','-target','x86_64-w64-mingw32','-static',(Join-Path $root 'tests\test-maycon-desktop-cards.cpp'),'-ldwmapi','-lgdi32','-lshell32','-lole32','-luuid','-o',$exe)
    & $compiler @argsTest
    if($LASTEXITCODE -ne 0){throw 'Settings test compilation failed'}
    & $exe
    if($LASTEXITCODE -ne 0){throw 'Settings tests failed'}
}
Write-Output 'Build complete. No mods were installed or activated.'

#Requires -Version 7.0
$ErrorActionPreference='Stop'
$root=Split-Path $PSScriptRoot -Parent
$mods=Get-Content -Raw -LiteralPath (Join-Path $root 'mods.json') | ConvertFrom-Json
$ids=[Collections.Generic.HashSet[string]]::new()
$repoUrl='https://github.com/MayconDIS/Windhawk_Mods'
$profileUrl='https://github.com/MayconDIS'
foreach($mod in $mods){
    if(-not $ids.Add($mod.id)){throw ('Duplicate mod ID: '+$mod.id)}
    $source=Get-Content -Raw -LiteralPath (Join-Path $root $mod.source)
    foreach($field in @('id','name','version')){
        $match=[regex]::Match($source,('(?m)^// @'+$field+'\s+(.+)$'))
        if(-not $match.Success -or $match.Groups[1].Value.Trim() -cne $mod.$field){throw ('Metadata mismatch: '+$mod.id+' / '+$field)}
    }
    if($source -notmatch '(?m)^// @license\s+GPL-3\.0-only\s*$'){throw ('Missing license metadata: '+$mod.id)}
    $readme=[regex]::Match($source,'(?s)// ==WindhawkModReadme==\s*/\*(.*?)\*/\s*// ==/WindhawkModReadme==')
    if(-not $readme.Success){throw ('Missing embedded guide: '+$mod.id)}
    $guide=Get-Content -Raw -LiteralPath (Join-Path $root $mod.guide)
    if($readme.Groups[1].Value.Trim() -cne $guide.Trim()){throw ('Embedded/local guide mismatch: '+$mod.id)}
    $footer=[regex]::Match($guide,'(?s)## Credits and links\s+(.+)\z')
    if(-not $footer.Success -or -not $footer.Value.Contains($repoUrl) -or -not $footer.Value.Contains($profileUrl)){throw ('Missing final credit links: '+$mod.id)}
    if($source -match 'C:[/\\]Users[/\\]mayco'){throw ('Personal machine path in source: '+$mod.id)}
    Write-Output ('PASS metadata, guide, and credits: '+$mod.id)
}
if(-not (Test-Path -LiteralPath (Join-Path $root 'LICENSE'))){throw 'Missing license file'}
Write-Output ('PASS collection: '+$mods.Count+' projects')

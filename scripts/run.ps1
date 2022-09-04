$currentPath = Get-Location
Set-Location $PSScriptRoot/..
".\build\Debug\BrickBreaker.exe" | Invoke-Expression
Set-Location $currentPath

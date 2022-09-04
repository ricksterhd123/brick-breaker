$currentPath = Get-Location
Set-Location $PSScriptRoot/..

if (!(Test-Path -PathType container build))
{
    mkdir build
}

# Build job
Set-Location .\build
# Config
cmake ..
# Build
cmake --build .
# Add libraries
Copy-Item -Recurse .\libs\SDL\Debug\* .\Debug\
Set-Location $currentPath
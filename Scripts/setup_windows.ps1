Write-Host "=== Creating virtual environment ==="

python -m venv .venv

.\.venv\Scripts\Activate.ps1

python -m pip install --upgrade pip

if (Test-Path "requirements\base.txt") {
    pip install -r requirements\base.txt
}

Write-Host ""
Write-Host "Done!"
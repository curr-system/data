Get-ChildItem *_15min.json -Name | Foreach {
    Write-Verbose $_ -Verbose
    ./randomizer/randomizer.exe $_ $_.Replace("15min", "10sec")
  }


$env:Path += ";C:\Program Files\MongoDB\Server\3.4\bin"
$data_path = "$HOME\Documents\curr-system\data\source\*_10sec.json"

Get-ChildItem $data_path | Foreach {
    $name = $_.Name.Replace("_10sec.json", "")
    Write-Verbose $name -Verbose
    mongoimport -d currs -c $name --type json --jsonArray --file $_.FullName --numInsertionWorkers 8
  }

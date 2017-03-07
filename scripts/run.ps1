Write-Verbose "Starting service" -Verbose
./Start-MongoDBService.ps1

Write-Verbose "Creating database" -Verbose
./Create-CurrsDB.ps1

Write-Verbose "Inserting data" -Verbose
./Insert-Data.ps1


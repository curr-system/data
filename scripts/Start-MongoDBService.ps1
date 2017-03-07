$env:Path += ";C:\Program Files\MongoDB\Server\3.4\bin"
$db_directory = "$HOME\Documents\curr-system\data\db"
$log_path = "$HOME\Documents\curr-system\data\mongo.log"

Write-Warning "RUN AS ADMINISTRATOR"

mongod --directoryperdb --dbpath $db_directory --logpath $log_path --logappend --rest --httpinterface --service --install

Start-Service MongoDB


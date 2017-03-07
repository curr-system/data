$url = "https://cinkciarz.pl/currencies_rates/get_intervals/{0}/900/{1}"
$currencies = @{
  "EUR" = 2
  "USD" = 1
  "CHF" = 4
}


$count = 2592000 * 6

foreach ($k in $currencies.Keys) {
  Invoke-WebRequest ($url -f ($currencies[$k], $count)) -OutFile "$k.json" -Verbose
}

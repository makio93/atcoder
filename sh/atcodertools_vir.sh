today=$(date "+%m%d")
if [ $(date "+%H") -lt $(date -d "12" "+%H") ]; then
  period="am"
else
  period="pm"
fi
folder=$today$period
atcoder-tools probgen ${@} --contest $folder --config /mnt/c/pg/atcodertools_vir.toml

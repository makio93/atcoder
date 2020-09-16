#!/bin/zsh
today=$(date "+%m%d")
if [ $(date "+%H") -lt $(date -d "12" "+%H") ]; then
  period="am"
else
  period="pm"
fi
dir=$today$period
atcoder-tools probgen ${@} --contest $dir --config /mnt/c/pg/atcodertools_vir.toml

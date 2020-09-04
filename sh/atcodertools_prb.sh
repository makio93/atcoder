#!/bin/zsh
problem=$1
keyword=$2
difficulty=("easy" "normal" "hard")
cmp=false
for key in "${difficulty[@]}";
do
  if [ $keyword = $key ]; then
    atcoder-tools probgen $problem --contest $keyword --config "/mnt/c/pg/atcodertools_prb.toml" --workspace "/mnt/c/pg/CMP/"
    cmp=true
  fi
done
if ! "${cmp}"; then
  atcoder-tools probgen $problem --contest $keyword --config "/mnt/c/pg/atcodertools_prb.toml" --workspace "/mnt/c/pg/PRB/"
fi

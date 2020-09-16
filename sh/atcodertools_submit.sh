bsname=`basename $1`
filename="${bsname%.*}"
extname="${bsname##*.}"
if [ "${extname}" = "cpp" ] ; then
  extname="out"
fi
atcoder-tools submit -u --code ./$bsname --exec ./$filename.$extname
# --unlock-safety, -u   By default, this script only submits the first code per problem. However, you can remove the safety by this option in order to submit codes twice or more.
# 2回以上提出する場合は -uオプションを付けてください。

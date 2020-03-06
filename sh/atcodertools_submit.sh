execfile=$1
atcoder-tools submit -u --code ./main${execfile}.cpp --exec ./main${execfile}.out
# --unlock-safety, -u   By default, this script only submits the first code per problem. However, you can remove the safety by this option in order to submit codes twice or more.
# 2回以上提出する場合は -uオプションを付けてください。

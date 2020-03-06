#!/bin/sh

#バックアップパス
bkpath="/mnt/c/WSL_Ubuntu/bkup"

# バックアップ先のディレクトリがあるか確認する
if [ ! -e $bkpath ]; then
# 存在しない場合、作成する
mkdir -p $bkpath
fi

# バックアップ
# バックアップフォルダ名（yyyyMMddHHmm）
today=$(date "+%Y%m%d%H%M")

# バックアップフォルダ作成
mkdir -p $bkpath/$today

# ルートディレクトリからtarで圧縮
sudo tar -cvpjf $bkpath/$today/backup.tar.bz2 -X $bkpath/exclude_list.txt /

# パッケージリストを作成（バックアップだけが目的であれば必要ない）
dpkg-query -f '${binary:Package}\n' -W >   $bkpath/$today/list_pkg.txt
pip list --format=columns > $bkpath/$today/list_pip.txt
tlmgr list --only-installed > $bkpath/$today/list_tex.txt

export LANG=ja_JP.UTF-8

#HOMEのpath
export PATH=/mnt/c/pg:$PATH
#シェルファイルの収納場所
export PATH=/mnt/c/pg/sh:$PATH

plugins=(… zsh-completions)
autoload -U compinit && compinit

HISTFILE=~/.zsh_history
HISTSIZE=1000000
SAVEHIST=1000000
# ヒストリを共有
setopt share_history
# 直前と同じコマンドをヒストリに追加しない
setopt hist_ignore_dups
# ヒストリを呼び出してから実行する間に一旦編集
setopt hist_verify
# zsh の開始, 終了時刻をヒストリファイルに書き込む
setopt extended_history
# スペースで始まるコマンド行はヒストリリストから削除
setopt hist_ignore_space
# 余分な空白は詰めて記録
setopt hist_reduce_blanks
# historyコマンドは履歴に登録しない
setopt hist_no_store
# 補完時にヒストリを自動的に展開
setopt hist_expand

# 補完
# 補完機能を有効にする
autoload -Uz compinit
compinit

# VCSの情報を取得するzsh関数
autoload -Uz vcs_info
autoload -Uz colors
colors
# black red green yellow blue magenta cyan white

# PROMPT変数内で変数参照
setopt prompt_subst

#gitの色
#通常
zstyle ':vcs_info:*' formats "%F{green}%c%u(%b)%f"
#formats 設定項目で %c,%u が使用可
zstyle ':vcs_info:git:*' check-for-changes true
#commit されていないファイルがある
zstyle ':vcs_info:git:*' stagedstr "%F{magenta}!"
#add されていないファイルがある
zstyle ':vcs_info:git:*' unstagedstr "%F{blue}+"
#rebase 途中,merge コンフリクト等 formats 外の表示
zstyle ':vcs_info:*' actionformats '[%b|%a]'

# %b ブランチ情報
# %a アクション名(mergeなど)
# %c changes
# %u uncommit

# プロンプト表示直前に vcs_info 呼び出し
precmd () { vcs_info }

# プロンプト（左）
# 2行表示
PROMPT="%{${fg[green]}%}[%n] %~%{${reset_color}%}
%# "

# プロンプト（右）
RPROMPT='${vcs_info_msg_0_} %{${fg[green]}%}%}%T%{${reset_color}%} '

zstyle ':completion:*' matcher-list 'm:{a-z}={A-Z}'
zstyle ':completion:*' ignore-parents parent pwd ..
zstyle ':completion:*:sudo:*' command-path /usr/local/sbin /usr/local/bin /usr/sbin /usr/bin /sbin /bin /usr/X11R6/bin

## 出力の文字列末尾に改行コードが無い場合でも表示
# unsetopt promptcr

## コアダンプサイズを制限
limit coredumpsize 102400

## 補完候補一覧でファイルの種別をマーク表示
setopt list_types

## 補完候補を一覧表示
setopt auto_list

## ファイル名で #, ~, ^ の 3 文字を正規表現として扱う
setopt extended_glob

## TAB で順に補完候補を切り替える
setopt auto_menu

## =command を command のパス名に展開する
setopt equals

## --prefix=/usr などの = 以降も補完
setopt magic_equal_subst

# ファイル名の展開で辞書順ではなく数値的にソート
setopt numeric_glob_sort

## 出力時8ビットを通す
setopt print_eight_bit

## 補完候補のカーソル選択を有効に
zstyle ':completion:*:default' menu select=1

## 補完候補の色づけ
zstyle ':completion:*:default' list-colors ${(s.:.)LS_COLORS}

## ディレクトリ名だけで cd
setopt auto_cd

## cd 時に自動で push
setopt autopushd

## 同じディレクトリを pushd しない
setopt pushd_ignore_dups

## カッコの対応などを自動的に補完
setopt auto_param_keys

## ディレクトリ名の補完で末尾の / を自動的に付加し、
# 次の補完に備える
setopt auto_param_slash

## スペルチェック
setopt correct

# cd -<TAB>で移動
# スタックの上限
DIRSTACKSIZE=100
setopt auto_pushd

#エイリアス
alias abc='atcodertools_gen.sh'
alias sub='atcodertools_submit.sh'
alias tes='atcodertools_test.sh'
alias arc='atcodertools_gen_arc.sh'
alias agc='atcodertools_gen_agc.sh'
alias oth='atcodertools_gen_oth.sh'
alias asa='atcodertools_gen_asa.sh'

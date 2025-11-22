# 今のフォルダを変数に保存  
OLD_DIR="$PWD"

# フォルダ名の決定
cd ~/atcoder/
echo "コンテスト名を入力=>"
read contestName
contestName=$(echo "$contestName" | tr '[:lower:]' '[:upper:]')
echo "この名前でコンテストを開始します=>\"$contestName\" y/n"
read isOK 
if [ "$contestName" != "y" ] && [ "$contestName" != "yes" ]
    exit 0
fi

# gitの更新

git fetch -p
git checkout main
git pull
git checkout -b $contestName main

# フォルダの作成･ファイルの移動
mkdir submission/ABC/$contestName
for letter in A B C D E F G; do
    cp material/template.py submission/ABC/$contestName/$contestName$letter.py
    done
for letter in A B; do
    cp material/template.cpp submission/ABC/$contestName/$contestName$letter.cpp
    done
# 終わったら元のフォルダへ戻る
cd "$OLD_DIR"

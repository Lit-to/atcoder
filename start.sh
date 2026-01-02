# 今のフォルダを変数に保存  
OLD_DIR="$PWD"

# フォルダ名の決定
cd ~/atcoder/
echo "コンテスト名を入力=>"
read contestName
contestName=$(echo "$contestName" | tr '[:lower:]' '[:upper:]')
echo "この名前でコンテストを開始します=>\"$contestName\" y/n"
read question
if [ "$question" != "y" ] && [ "$question" != "yes" ];then
    echo "中断しました"
    exit 0
fi

# gitの更新
git push
git checkout main
git pull -p
git checkout -b $contestName main
git checkout $contestName

# フォルダの作成･ファイルの移動
for letter in A B C D E F G; do
    cp modules/template.py dev/$contestName$letter.py
    sed -i "1i # $contestName$letter" dev/$contestName$letter.py
    done
for letter in C D; do
    cp modules/template.cpp dev/$contestName$letter.cpp
    sed -i "1i // $contestName$letter" dev/$contestName$letter.cpp
    done
# 終わったら元のフォルダへ戻る
cd "$OLD_DIR"

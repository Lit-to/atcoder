# 今のフォルダを変数に保存  
OLD_DIR="$PWD"

# 移動する  
cd ~/atcoder/

echo "コンテスト名を入力=>"
read contestName
mkdir submission/ABC/$contestName

for letter in A B C D E F G; do
    cp material/template.py submission/ABC/$contestName/$contestName$letter.py
    done
for letter in A B; do
    cp material/template.cpp submission/ABC/$contestName/$contestName$letter.cpp
    done
# 終わったら元のフォルダへ戻る
cd "$OLD_DIR"

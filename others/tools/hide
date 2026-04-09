param="$1"
OLD_DIR="$PWD"
cd ~/atcoder/
if [[ $param == "hide" ]]; then
    cp ./.vscode/settings_lock.json ./.vscode/settings.json
fi
if [[ $param == "show" ]]; then
    cp ./.vscode/settings_unlock.json ./.vscode/settings.json
fi

cd $OLD_DIR

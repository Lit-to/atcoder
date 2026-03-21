param="$1"
if [[ $param == "lock" ]]; then
    cp ./.vscode/settings_lock.json ./.vscode/settings.json
fi
if [[ $param == "unlock" ]]; then
    cp ./.vscode/settings_unlock.json ./.vscode/settings.json
fi


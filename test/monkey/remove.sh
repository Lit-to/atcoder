read -p "do you want to delete test dir? (y/n): " CONFIRM

if [[ "$CONFIRM" != "y" && "$CONFIRM" != "Y" ]]; then
    echo "finished."
    exit 0
fi

pushd "$(dirname "$0")" > /dev/null || exit 1
rm -rfd TEST
echo "deleted."
popd > /dev/null

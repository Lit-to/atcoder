OLD_DIR="$PWD"
cd ~/atcoder/submission

find . -type f | while read -r f; do
  tail -n +2 "$f" | sha256sum | awk "{print \$1, \"$f\"}"
done | sort | awk '
{
  hash=$1
  file=$2
  group[hash]=group[hash] file "\n"
  count[hash]++
}
END {
  for (h in count) {
    if (count[h] > 1) {
      printf "## %d files\n\n", count[h]
      n = split(group[h], arr, "\n")
      for (i = 1; i <= n; i++) {
        if (arr[i] != "") {
          printf "- %s\n", arr[i]
        }
      }
      print ""
    }
  }
}'

cd $OLD_DIR

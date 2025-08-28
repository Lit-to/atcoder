rm -rfd ./docs/source
rm -rfd ./docs/sphinx
rm -rfd ./docs/out
mkdir ./docs/source
cp ./lang/python/material/* ./docs/source/
sphinx-quickstart -q -p atcoder -a Lit_to -v 1.0.0 ./docs/sphinx
sphinx-apidoc -f -o ./docs/sphinx ./docs/source
cp docs/boot/conf.py docs/sphinx/conf.py
cp docs/boot/index.rst docs/sphinx/index.rst
make -C docs/sphinx/ html
echo "show this > ./docs/sphinx/_build/html/index.html "
cmd.exe /C start "" "$(wslpath -w ./docs/sphinx/_build/html/index.html)"

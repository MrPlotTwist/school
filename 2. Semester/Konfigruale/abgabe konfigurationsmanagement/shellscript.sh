#!/bin/bash
# shellscript:
git init
echo "# Test" >> README.md
git add README.md
git commit -m "first commit"
# global config
echo "global config:"
git config --global user.name "tomi"
git config --global user.email "tomi2002@gmx.at"
# creating a text file
echo "creating a text file:"
touch example.txt
echo "sample text" >> example.txt
git add example.txt
git commit -m "example text file"
# git status
echo "git status:"
git status
git add shellscript.sh
git commit -m "shellscript"
git status
# SHA1 key finden + Inhalt anzeigen
echo "SHA1 key finden + Inhalt anzeigen"
hash=$(git hash-object example.txt)
git cat-file -p $hash
# "Hello World!" schreiben, aber keine File erstellen und den SHA1 key in Variable speichern, anschließend ausgeben
echo "Hello World! ausgeben, aber keine File erstellen und den SHA1 key in Variable speichern, anschließend ausgeben"
hash=$(echo -n "Hello World!" | git hash-object -w --stdin)
echo $hash
# alias erstellen
echo "alias erstellen:"
git config --global alias.lol "log --graph --decorate --oneline --all"
git lol
# neue datei erstellen und andere datei zum momentanen commit hinzufügen
echo "neue datei erstellen und andere datei zum momentanen commit hinzufügen:"
echo "neue Datei" >> neue_datei.txt
git add neue_datei.txt
git commit -m "neue Datei"
cat neue_datei.txt
echo "lorem ipsum" >> andere_datei.txt
git add andere_datei.txt
git commit --amend --no-edit
# Datei entfernen und wiederherstellen
echo "Datei entfernen und wiederherstellen:"
git rm example.txt
git restore --staged example.txt
git restore example.txt
echo "new text" >> example.txt
git add example.txt
git commit -m "changes"
# modify files
echo "modify files:"
echo "new text" >> example.txt
cat example.txt
git status
git add example.txt
git commit -m "idk"
# Zu vorletztem Commit zurückkehren
echo "zu vorletztem commit zurückkehren"
git lol
git checkout HEAD~1
git lol


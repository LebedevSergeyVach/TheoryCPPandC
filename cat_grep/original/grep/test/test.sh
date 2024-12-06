#!/bin/bash

echo "Тест 1: отсутсвие флагов, шаблон: TAB, файлы: *.txt"
../s21_grep TAB ../txt_test/*.txt > 1_s21.txt
grep TAB ../txt_test/*.txt > 1_grep.txt
diff 1_s21.txt 1_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 2: флаг -i, шаблон: WORLD, файлы: *.txt"
../s21_grep -i WORLD ../txt_test/*.txt > 2_s21.txt
grep -i WORLD ../txt_test/*.txt > 2_grep.txt
diff 2_s21.txt 2_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 3: флаг -e, шаблоны: \"Привет\" \"C!\", файлы: *.txt"
../s21_grep -e "Привет" -e "C!" ../txt_test/*.txt > 3_s21.txt
grep -e "Привет" -e "C!" ../txt_test/*.txt > 3_grep.txt
diff 3_s21.txt 3_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 4: флаг -v, шаблон: "Programing on C!", файлы: *.txt"
../s21_grep -v "Programing on C!" ../txt_test/*.txt > 4_s21.txt
grep -v "Programing on C!" ../txt_test/*.txt > 4_grep.txt
diff 4_s21.txt 4_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 5: флаг -c, шаблон: Привет, файлы: *.txt"
../s21_grep -c "Привет" ../txt_test/*.txt > 5_s21.txt
grep -c "Привет" ../txt_test/*.txt > 5_grep.txt
diff 5_s21.txt 5_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 6: флаг -l, шаблон: Привет, файлы: *.txt"
../s21_grep -l "Привет" ../txt_test/*.txt > 6_s21.txt
grep -l "Привет" ../txt_test/*.txt > 6_grep.txt
diff 6_s21.txt 6_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 7: флаг -n, шаблон: Программирование на C!, файлы: *.txt"
../s21_grep -n "Программирование на C!" ../txt_test/*.txt > 7_s21.txt
grep -n "Программирование на C!" ../txt_test/*.txt > 7_grep.txt
diff 7_s21.txt 7_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 8: флаг -h, шаблон: [1-5], файлы: *.txt"
../s21_grep -h "[1-5]" ../txt_test/*.txt > 8_s21.txt
grep -h "[1-5]" ../txt_test/*.txt > 8_grep.txt
diff 8_s21.txt 8_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 9: флаг -f, шаблон: file_patterns, файлы: *.txt"
../s21_grep -f ../txt_test/pattern ../txt_test/*.txt > 9_s21.txt
grep -f ../txt_test/pattern ../txt_test/*.txt > 9_grep.txt
diff 9_s21.txt 9_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 10: флаг -e, шаблон: [0-9] [a-f], файлы: *.txt"
../s21_grep -e "[0-9]" -e "[a-f]" ../txt_test/*.txt > 10_s21.txt
grep -e "[0-9]" -e "[a-f]" ../txt_test/*.txt > 10_grep.txt
diff 10_s21.txt 10_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi



echo "Тест 11: флаг -e, шаблон: \"@#$%^&\" \",\", файлы: *.txt"
../s21_grep -e "@#$%^&" -e "," ../txt_test/*.txt > 11_s21.txt
grep -e "@#$%^&" -e "," ../txt_test/*.txt > 11_grep.txt
diff 11_s21.txt 11_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi

echo "Тест 12: флаг -in -hc -f txt_test/patten, шаблон: , файлы: *.txt"
../s21_grep -in -hc -f ../txt_test/pattern ../txt_test/*.txt > 12_s21.txt
grep -in -hc -f ../txt_test/pattern ../txt_test/*.txt > 12_grep.txt
diff 12_s21.txt 12_grep.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi

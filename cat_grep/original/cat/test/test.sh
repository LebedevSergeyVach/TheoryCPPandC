#!/bin/bash

echo "Тест 1: отсутсвие флагов"
../s21_cat ../txt_test/test.txt > 1_s21.txt
cat ../txt_test/test.txt > 1_cat.txt
diff 1_s21.txt 1_cat.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 2: флаг -n"
../s21_cat -n ../txt_test/test.txt > 2_s21.txt
cat -n ../txt_test/test.txt > 2_cat.txt
diff 2_s21.txt 2_cat.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 3: флаг -b"
../s21_cat -b ../txt_test/test.txt > 3_s21.txt
cat -b ../txt_test/test.txt > 3_cat.txt
diff 3_s21.txt 3_cat.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 4: флаг -s"
../s21_cat -s ../txt_test/test.txt > 4_s21.txt
cat -s ../txt_test/test.txt > 4_cat.txt
diff 4_s21.txt 4_cat.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 5: флаг -t"
../s21_cat -t ../txt_test/test.txt > 5_s21.txt
cat -t ../txt_test/test.txt > 5_cat.txt
diff 5_s21.txt 5_cat.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 6: флаг -v"
../s21_cat -v ../txt_test/test.txt > 6_s21.txt
cat -v ../txt_test/test.txt > 6_cat.txt
diff 6_s21.txt 6_cat.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 7: флаг -e"
../s21_cat -e ../txt_test/test.txt > 7_s21.txt
cat -e ../txt_test/test.txt > 7_cat.txt
diff 7_s21.txt 7_cat.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 8: флаг -E"
../s21_cat -E ../txt_test/test.txt > 8_s21.txt
cat -E ../txt_test/test.txt > 8_cat.txt
diff 8_s21.txt 8_cat.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi


echo "Тест 9: флаг -T"
../s21_cat -T ../txt_test/test.txt > 9_s21.txt
cat -T ../txt_test/test.txt > 9_cat.txt
diff 9_s21.txt 9_cat.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi

echo "Тест 10: все флаги"
../s21_cat -b -n -s -v -t -e -T -E ../txt_test/test.txt > 10_s21.txt
cat -b -n -s -v -t -e -T -E ../txt_test/test.txt > 10_cat.txt
diff 10_s21.txt 10_cat.txt > /dev/null
if [[ $? != 0 ]]
then
    echo "FAILED"
else
    echo "SUCCESS"
fi

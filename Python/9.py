# coding=gbk
import copy
import wx
import wx.grid
import time


# 帮我一行加注释
grammar = []  # 文法
itemSet = []  # 项目集
DFA = []
Vn = []  # 非终结符号
Vt = []  # 终结符号

# 闭包运算


def closure(item):
    global itemSet
    # 定义一个列表，用来存放项目集
    dot = []
    # 将item加入到dot中
    dot.append(item)
    # 定义一个列表，用来存放旧的项目集
    olddot = []
    # 下面代码的作用
    # 1.找到·后面的非终结符号
    # 2.找到产生式左边为·后面的非终结符号的产生式
    # 3.将产生式加入到dot中
    while len(dot) != len(olddot):
        # 将dot赋值给olddot
        olddot = copy.deepcopy(dot)
        # 遍历dot
        temp = []
        for i in range(len(dot)):
            # 遍历项目集
            for j in range(len(itemSet)):
                # 判断·后面的字符是否为非终结符号
                if dot[i].index('·') + 1 < len(dot[i]) and dot[i][dot[i].index('·') + 1] == itemSet[j][0] and \
                        itemSet[j][itemSet[j].index('>') + 1] == '·':
                    # 将产生式加入到temp中
                    temp.append(itemSet[j])
        # 将temp中的产生式加入到dot中
        for k in range(len(temp)):
            # 判断产生式是否在dot中
            if temp[k] not in dot:
                # 将产生式加入到dot中
                dot.append(temp[k])
    # 返回dot
    return dot


# 移进运算
def goto(item, a):
    # 定义全局变量
    global itemSet
    # 1.找到·后面的非终结符号
    # 2.找到产生式左边为·后面的非终结符号的产生式
    # 3.将产生式加入到dot中
    for i in range(len(item)):
        # 找到·
        if item[i] == '·' and i != len(item) - 1:
            # 判断·后面的字符是否为a
            if item[i + 1] == a:
                # 将·后面的字符移到·前面
                item2 = item[:i] + item[i + 1] + '·' + item[i + 2:]
                # 返回移进后的项目集
                if item2 in itemSet:
                    return item2
    return -1

# 查找项目集在DFA中的位置


def findItem(item):
    # 定义全局变量
    global DFA
    # 遍历DFA
    for i in range(len(DFA)):
        # 判断项目集是否在DFA中
        if item in DFA[i]:
            # 返回项目集在DFA中的位置
            return i
    return -1


# 查找项目集在DFA中的位置
n = int(input('输入个数'))
# 输入文法
for i in range(n):
    # 输入产生式
    temp = input()
    # 判断是否为开始符号
    if i == 0:
        # 将开始符号加入到文法中
        grammar.append('S\'->' + temp[0])
    # 将产生式加入到文法中
    grammar.append(temp)
    # 遍历产生式
    for j in range(len(temp)):
        # 判断是否为非终结符号
        if temp[j].isupper() and temp[j] not in Vn:
            # 将非终结符号加入到Vn中
            Vn.append(temp[j])
        # 判断是否为终结符号
        elif temp[j].islower() and temp[j] not in Vt:
            # 将终结符号加入到Vt中
            Vt.append(temp[j])
# 将终结符号加入到Vn中
Vn.sort()
# 将终结符号加入到Vt中
Vt.sort()

# 遍历文法
for i in range(len(grammar)):
    # 定义一个标志位
    flag = 0
    # 遍历产生式
    for j in range(len(grammar[i])):
        # 判断是否为->
        if grammar[i][j] == '>':
            flag = 1
        if flag == 1 and grammar[i][j] != '>':
            # 将产生式加入到itemSet中
            temp = grammar[i][:j] + '·' + grammar[i][j:]
            # 将产生式加入到itemSet中
            itemSet.append(temp)
        # 判断是否为|
    itemSet.append(grammar[i] + '·')

# 打印文法
print(grammar)
# 打印项目集
DFA.append(closure(itemSet[0]))

# 定义一个列表，用来存放旧的DFA
oldDFA = []

while len(oldDFA) != len(DFA):
    # 将DFA赋值给oldDFA
    oldDFA = copy.de

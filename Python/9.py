def find_most_frequent_letter(s):
    # 创建一个字典来存储每个字母及其出现的次数
    count_dict = {}
    for letter in s:
        if letter in count_dict:
            count_dict[letter] += 1
        else:
            count_dict[letter] = 1

    # 找出出现次数最多的字母
    most_frequent_letter = max(count_dict, key=count_dict.get)
    return most_frequent_letter
    

# 测试
s = "hello world"
print(find_most_frequent_letter(s))


a={'a':23,'b':34,'c':45,'d':56,'e':67,'f':78,'g':89,'h':90,'i':12,'j':23,'k':34,'l':45,'m':56,'n':67,'o':78,'p':89,'q':90,'r':12,'s':23,'t':34,'u':45,'v':56,'w':67,'x':78,'y':89,'z':90}
print(a)
print(a.keys())
print(max(a))
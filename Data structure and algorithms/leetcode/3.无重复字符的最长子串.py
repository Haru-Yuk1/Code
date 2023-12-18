s=input()
news=''
count=0
for i in s:
    if i in news:
        news=news[news.index(i)+1:]
    news+=i
    if len(news)>count:
        count=len(news)
print(count)

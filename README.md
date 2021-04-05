# Js锁
运行时动态解密OTv3的JavaScript脚本 

理论上它支持更高的版本,因为OneTap都会经过fopen

English Ver on the down
# 关于 Js 锁
通过异或解密事先加密好的JavaScript文件，实际上如果key还是存储在本地且动态还是能够被破解。
(我建议你可以使用php,每当有js下载的请求时便动态异或加密，然后本地key也会联网获取，这样就能保证其一定程度的安全性)
在 https://github.com/extremeblackliu/JsLock/blob/main/dllmain.cpp#L52 这行里面
我建议你更换成  buffer_ = malloc(size);
硬编码是非常坏的习惯，具体怎么弄看你自己怎么写，不要只管我要更新。
在 https://github.com/extremeblackliu/JsLock/blob/main/dllmain.cpp#L56 这行里面
其实就是图个方便，也没有别的意思，还是那句话，具体怎么弄看你自己。
对了，我认为如果解密之后不清除相关信息，容易被下断点拿到原文，使用完之后，应该用memset();来清空
或者用free()释放内存，正好对应上面的malloc()

# 聊一聊Js锁吧
往控制台打印文本已经是很低级的东西了,我建议你应该自己完成。

更新了dllmain,纠正一下我说的话，我是说密钥已经泄露所以直接使用密钥这个加解密已经不安全

另外,不要笑那个硬编码,这只是第一个版本。

你们可以在github上pull request来改进，我看到我会处理的。

或者是自己下载并改进代码,这里拥有完好可运行的框架,实际上写的有点垃圾,因为这是第一个版本,写的比较急促。

但是有完整的框架，只需要你做一些反调试啊，反解密啊，混淆啊，模块隐藏啊，等等...你想做的都可以做。

这里还有很多注释，非常容易看懂。

-By ExtremeBlackLiu-

# JsLock
Runtime Decrypt OTv3 JavaScript

May its can support more higher version of OneTap,cuz onetap load js from fopen , fread.

# Say something about JsLock?
print text in console is the lower level topic,i suggest u should do it by u self

idc about u copy or paste , or try to sell it , dont forget the owner , but yeah just like i say nothing .

for usually , i dont suggest u use xor to encode/decode the file , cuz its not that safety.

another thing , dont laugh on that hardcode,its just my first version , my third version most problem got solved.

u can pull request to improve the jslock , when i saw ill accept it.

or u can download the code and improve the code , this is working framework,even its kinda trash , cuz its first version(again)

but still yea, fully working framework, u can do some anti-debug , anti-string, hidemodule etc... do u wanna do.

and there is lots of note u can read the code easily(btw its Chinese).

# Js锁
运行时动态解密OTv3的JavaScript脚本 

理论上它支持更高的版本,因为OneTap都会经过fopen

English Ver on the down
# 聊一聊Js锁吧
往控制台打印文本已经是很低级的东西了,我建议你应该自己完成。

无论你是复制粘贴出售又或者是拿去炫耀自己的结果,不要忘记原作者,虽然我说这句话作用不大xdd。

我通常不建议你用这个异或的方式去加解密,因为已经不安全。

另外,不要笑那个硬编码,这只是第一个版本。

你们可以在github上pull request来改进，我看到我会处理的。

或者是自己下载并改进代码,这里拥有完好可运行的框架,实际上写的有点垃圾,因为这是第一个版本,写的比较急促。

但是有完整的框架，只需要你做一些反调试啊，反解密啊，混淆啊，模块隐藏啊，等等...你想做的都可以做。

这里还有很多注释，非常容易看懂。

-By ExtremeBlackLiu-
```cpp
/*
题外话
这里嘲讽一下我们的出参大神 东哥
大号被MC圈子挂云黑，所以现在你们看他的号很干净，因为是小号，之前他跟wiki起冲突Wiki都没查到他q绑。
因为莫心看不起我而把我换下来把东哥换上去。
实际上你们也可以看到，东哥的东西质量都不咋地，LauncherSU 0.5.8的源码泄露在莫心的内部群
因此东哥实际上从旧版的LauncherSU复制粘贴了不少东西，另外我要嘲笑他，Js锁就这么简单的东西还琢磨不透
不过也是，技术很差但是喜欢装的人多了去了，我只是懒得理他。我猜东哥看到Js锁开源之后又要复制粘贴一个"东哥锁"了吧
期待你的作品，xddddd
黑历史莫心多了去了，其实我一直都不傻，只是装作跟莫心装不知道而已，人人都有心机
这里也懒得说了，过去的都过去了，不过还是得列出一条没影响到多数人的，免得又说我吹牛逼了
就是wish当时好像确实只给莫心供应邀请码，但是你知道，垄断的后果吗？
没错，莫心疯了一样，把邀请码提到4000块钱，因为他垄断了，除了他以外没有人知道价格其实还是2000多块钱没有涨(真的是除他以外，当时连我也不知道)
不过后面他自己在他内部群说漏嘴，说他给别人返现600自己还有赚1000块钱，所以被我知道了，这个秘密基本上没有几个人知道。
说实话，我现在倒是希望东哥继续跟莫心干，死得快那是杠杠的xdddd
现在其实还有很多旧的人在老群里面什么也不知道，被蒙在鼓里，不过我也不在乎那些人。
*/
```
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

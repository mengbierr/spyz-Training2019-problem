{{ self.title() }}

{{ s('description') }}

everlasting觉得太无聊了，于是决定和蒟蒻yyc玩游戏！

他们会玩T轮游戏，每轮游戏中有若干局，他们的初始积分为1，每局的分值为k，输的人的得分乘k，赢的人得分乘k^2。每轮游戏后，everlasting都会询问这次游戏双方的得分，但yyc记不住得分只能随口说两个得分。但他不知道这两个数最终会不会成为两个人的得分。于是yyc决定向你求助！


{{ s('input format') }}

{{ self.input_file() }}

第一行一个正整数T，表示游戏轮数。

接下来T行，每行两个数x,y，表示yyc随口说出的两个人的得分。

{{ s('output format') }}

{{ self.output_file() }}

T行，每行一个“Yes”或“No”。表示这两个数是否合法。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

第一轮中，一局游戏k=3.

第二轮中，两局游戏k=2,每人赢一局。

第三轮中k=5和7，两个人分别赢一局。

{{ s('sample', 2) }}

{{ self.sample_file() }}

{{ s('hint') }}

请选手用较快的输入输出方式进行数据处理。

{{ s('subtasks') }}

{{ img('sample.png', size = 1, align = 'middle', inline = False) }}

{{ img('sample2.png', size = 1, align = 'middle', inline = False) }}


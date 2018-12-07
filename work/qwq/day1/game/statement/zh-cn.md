{{ self.title() }}

{{ s('description') }}

小L，小Y和小Z玩N局游戏，开始时他们约定好这局游戏的分数，但由于意见不统一，于是每个人都有自己对应的分数，但是游戏有输赢，只有两个人能得到自己的分数，现在小L想知道当他们得分相同时，他们的最大得分。

{{ s('input format') }}

{{ self.input_file() }}

第一行一个整数N.

接下来N行，表示每个人每局游戏对应的得分

{{ s('output format') }}

{{ self.output_file() }}

输出最大得分。无解输出“Impossible”（不包括括号）

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('subtasks') }}

对30%数据，N<=10

对100%数据，N<=25,得分<=1000000
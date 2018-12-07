{{ self.title() }}


{{ s('description') }}
在一个2维平面上有两条传送带，每一条传送带可以看成是一条线段。两条传送带分别为线段AB和线段CD。小L在AB上的移动速度为$P$，在CD上的移动速度为Q，在平面上的移动速度$R$。现在小L想从A点走到D点，他想知道最少需要走多长时间


{{ s('input format') }}

{{ self.input_file() }}
输入数据第一行是4个整数，表示A和B的坐标，分别为$A_x，A_y，B_x，B_y$

第二行是4个整数，表示C和D的坐标，分别为$C_x，C_y，D_x，D_y$

第三行是3个整数，分别是$P，Q，R$

{{ s('output format') }}

{{ self.output_file() }}

输出数据为一行，表示小L从A点走到D点的最短时间，保留到小数点后2位

{{ s('sample', 1) }}

{{ self.sample_text() }}


{{ s('subtasks') }}
对于100%的数据，1<= Ax，Ay，Bx，By，Cx，Cy，Dx，Dy<=1000
1<=P，Q，R<=10
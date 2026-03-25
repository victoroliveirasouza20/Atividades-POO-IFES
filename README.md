
###QUESTÕES DE REVISÃO ATVIIDADE 5######

1- Uma herança sozinha não garante polimorfismo porque, sem virtual, a linguagem C++ decide em tempo de compilação qual método chamar, não considerando o tipo real do objeto.

2- Ao declarar um método como virtual, o programa passa a escolher a implementação em tempo de execução, permitindo que cada classe derivada tenha seu próprio comportamento.

3- Usar um vector da classe base permite controlar vários equipamentos diferentes de forma uniforme, simplificando o código e facilitando manutenção e expansão do sistema
=================================================================================
######QUESTÕES DE REVISÃO ATIVIDADE 4######

1 - A diferença está no nível de acesso das classes derivadas. Se for 'private' o membro só pode ser acessado dentro da própria classe. Já 'protected', o membro não é 'public', mas pode ser acessado por uma classe derivada.

2 - Em situações muito específicas, por exemplo, inspeção técnica.

3 - A herança pública deve ser usada quando existe uma relação do tipo “é um” (is-a), ou seja, a classe derivada é uma especialização da classe base e herda suas características de forma natural.
Já a composição deve ser usada quando existe uma relação do tipo “tem um” (has-a), ou seja, uma classe utiliza outra como parte de sua estrutura, sem necessariamente ser uma especialização dela.

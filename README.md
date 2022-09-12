# 21a-emb-aps1

Embarcados - APS 1 - Musical!

Para maiores informações acesse:

https://insper.github.io/ComputacaoEmbarcada/APS-1-Musical/

Issues serão abertos neste repositório para guiar o desenvolvimento
da dupla. **Vocês não devem fechar os issues, apenas a equipe de professores!**, porém devem referenciar nos commits quando um issue 
foi concluído! Isso gerará um PR no classroom que será avaliado pela equipe.

## Documentação

TODO: Aualizar pinos

| Função  | PINO (ex: PA11) |
|---------|-----------------|
| BUZZER  |       PA21      |
| START   |       PD28      |
| SELEÇÃO |       PC31      |

### Imagem da montagem

![Montagem](img/montagem.jpeg)

### Estruturação do código
O código foi organizado com as funções, configurações de pinos e loop principal no main.c enquanto que as músicas utilizadas foram organizadas em arquivos .h, sendo cada música um struct que contém melodia, tempo e quantidade de notas.

### Vídeo do projeto

Link para vídeo no youtube : https://youtu.be/0WLHlg20Cck

### Músicas e Direitos autorais

1. Mario Bros Theme          - https://github.com/robsoncouto/arduino-songs/blob/master/supermariobros/supermariobros.ino
2. Asa Branca - Luiz Gonzaga - https://github.com/robsoncouto/arduino-songs/blob/master/asabranca/asabranca.ino
3. Jigglypuff Song           - https://github.com/robsoncouto/arduino-songs/blob/master/jigglypuffsong/jigglypuffsong.ino
4. Harry Potter Theme        - https://github.com/robsoncouto/arduino-songs/blob/master/harrypotter/harrypotter.ino
5. Happy Birthday            - https://github.com/robsoncouto/arduino-songs/blob/master/happybirthday/happybirthday.ino
6. Merry Christmas           - https://github.com/robsoncouto/arduino-songs/blob/master/merrychristmas/merrychristmas.ino


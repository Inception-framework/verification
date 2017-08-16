readelf -s $1 |  awk --non-decimal-data \
'BEGIN{for(i=1;i<4;i++){getline}}{if(NF==8) {printf("%d %s\n","0x"$2,$8)}}' \
> ST.txt

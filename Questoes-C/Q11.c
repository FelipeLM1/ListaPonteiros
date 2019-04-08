/*11) Para char x[4] o incremento foi igual o esperado : 
	
	  x=6422092
	x+1=6422093
	x+2=6422094
	x+3=6422094

O incremento foi de 1, pois cada  elemento char ocupar apenas 1 byte.

Para int x[4] o incremento foi o diferente da questão passada: 

	  x=6422080
	x+1=6422084
	x+2=6422088
	x+3=6422092

O incremento foi de 4 bytes para cada elemento inteiro, isso acontece pois 
o int no meu pc ocupa 4 bytes e pode ser mostrado com a função sizeof(int).

Para float x[4] o incremento foi igual da questão passada:

	  x=6422080
	x+1=6422084
	x+2=6422088
	x+3=6422092

Nesse caso cada elemento float ocupa 4 bytes, da mesma forma da questão anterior.*/

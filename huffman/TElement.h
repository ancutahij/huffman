#pragma once
typedef int TFrequency;
typedef char TCharacter;

/*
	Clasa TElment este responsabila de pastrarea informatiei utile din fiecare nod.
	Contine:
	-frecventa(numarul de aparitii al fiecarui caracter)
	-caracterul in sine
*/
class TElement {
	TFrequency freq;
	TCharacter ch;
public:
	TElement( TCharacter character, TFrequency frequency)
		: freq{frequency}, ch{character}{}
	TElement() {}
	//Getter pentru frecventa
	TFrequency getFrequency() const;
	//Getter pentru caracter
	TCharacter getCharacter() const;

};
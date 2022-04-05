const dodaj = document.querySelector('#but1');
const oblicz = document.querySelector('#but2');
const nazwa = document.querySelector('#nazwa');
const cena = document.querySelector('#cena');
const lista = document.querySelector('ul');
const suma = document.querySelector('p');
let wartosc = 0;

dodaj.addEventListener('click',() => {
    if(cena.value != '' && nazwa.value != ''){
        const item = document.createElement('li');
        const button = document.createElement('button');
        const price = parseFloat(cena.value);
        item.innerText = `${nazwa.value} : ${cena.value} zł`;
        button.innerText = 'X';
        item.appendChild(button);
        lista.appendChild(item);
        wartosc += parseFloat(cena.value);
        button.addEventListener('click', () => {
            item.parentElement.removeChild(item);
            wartosc -= price; 
        })
    }
    else{
        alert('Pola nie moga być puste');
    }
    nazwa.value='';
    cena.value='';
});

oblicz.addEventListener('click',() => {
    suma.innerText = `${wartosc} zł` ;
});
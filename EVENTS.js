const kolor = document.querySelector('#color');
const rozmiar = document.querySelector('#size');
const płótno = document.querySelector('div');

płótno.addEventListener('click', ()=>{
    const sumaElementów = (500*500)/(rozmiar.value*rozmiar.value);
    const divTab = [];
    for(let i = 0; i < sumaElementów; i++)
    {
        divTab.push(document.createElement('div'));
        divTab[i].style.width = rozmiar.value;
        divTab[i].style.height = rozmiar.value;
        //divTab[i].style.float = 'left';
        płótno.appendChild(divTab[i]);
    }
    
});

płótno.addEventListener('click', (e)=>{
    e.target.style.backgroundColor = kolor.value;

});
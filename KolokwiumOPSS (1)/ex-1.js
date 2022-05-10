const div = document.querySelector('div');
const p = document.querySelector('p');

for(let i=0; i < 4; i++){
    div.insertBefore(div.lastElementChild,'div');
}

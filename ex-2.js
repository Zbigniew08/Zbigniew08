const select = document.querySelector('select');
const h1 = document.querySelector('h1');
select.addEventListener('change', createCalendar);

function createCalendar()
{
    h1.innerText = select.value;
    
}
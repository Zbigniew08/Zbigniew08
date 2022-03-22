const select = document.querySelector('select');
const h1 = document.querySelector('h1');
const table = document.querySelectorAll('tr *');
select.addEventListener('change', createCalendar);

function fillCalendar( a, b)
{
    for(let i = 0; i < b; i++)
    {
        table[i + 6 + a].textContent = i+1;
    }
}

function clearCalendar()
{
    for(let i = 0; i < 49; i++)
    {
        table[i + 6].textContent = '';
    }
}

function createCalendar()
{
    h1.innerText = selectChildren[select.value-1].textContent;
    let d_t = new Date(2022, select.value-1).getDay();
    let d_w_m = new Date(2022, select.value, 0).getDate();
    clearCalendar();
    fillCalendar(d_t, d_w_m);
    
}

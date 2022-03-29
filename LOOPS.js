const button = document.querySelector('button');
const inputs = document.querySelectorAll('input');
const div = document.querySelector('div');
const próbki = [];
const histogram = [];
button.addEventListener('click',statLab);

function statLab()
{
    const ilość = inputs[0].value;
    const przedziały = inputs[1].value;
    generowaniePróbek(ilość);
    zerowanieTablicy(przedziały);
    zliczaniePróbek(przedziały);
}

function generowaniePróbek(ilość)
{
    for(let i = 0; i < ilość; i++)
    {
        próbki.push(Math.random());
    }
}

function zliczaniePróbek(przedziały)
{
    for(let i of próbki)
    {
        for(let k = 1; k < przedziały+1; k++)
        {
            if(i < (1/przedziały) * k)
            {
                histogram[k-1] += 1;
            }
        }
    }
}

function zerowanieTablicy(przedziały)
{
    for(let i = 0; i < przedziały; i++)
    {
        histogram[i] = 0;
    }
}

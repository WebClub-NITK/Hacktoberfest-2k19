

let show_diff_text_container = document.querySelector('.show-difference-container');

let paragraph_1_element = document.querySelector('.paragraph-1');
let paragraph_2_element = document.querySelector('.paragraph-2');

let paragraph1text;
let paragraph2text;

const setDiffText = () => {
    show_diff_text_container = document.querySelector('.show-difference-container');
    paragraph_1_element =      document.querySelector('.paragraph-1');
    paragraph_2_element =      document.querySelector('.paragraph-2');

    let p1_array = paragraph_1_element.value.split(/(\s+)/)

    let p2_array = paragraph_2_element.value.split(/(\s+)/)

    show_diff_text_container.innerHTML = '';

    for(let i = 0; i < p1_array.length; i++)
    {
        let span = document.createElement('span');
        if(p2_array.length > 0 && p1_array[i] != p2_array[i])
        {
            span.style.background = '#00dd00';

            if(p2_array[i] != undefined)
            {
                let spandiff = document.createElement('span');
                spandiff.innerText = p2_array[i];
                spandiff.style.background = '#dd0000';
                show_diff_text_container.appendChild(spandiff);
            }
        }
        span.innerText = p1_array[i];
        show_diff_text_container.appendChild(span);
    }

}

// this is for a more 'check every certain number of seconds' type of effect, rather than after typing
// window.setInterval( setDiffText, 500);
paragraph_1_element.addEventListener('keyup', setDiffText);

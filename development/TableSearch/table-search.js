
let input = document.querySelector('input');

input.addEventListener('keyup', () => {
    displayRows();
} )

const displayRows = () => {

    let table = document.querySelector('table');

    let allrows = table.children[0].children;
    allrows = [...allrows];

    let value = input.value.toLowerCase();


    allrows.map( (eachrow, index) => {
        if(index > 0) {
            if(eachrow.innerText.toLowerCase().indexOf(value) > -1) {
                eachrow.style.display = '';
            } else {
                eachrow.style.display = 'none';
            }
        }
    })

}
var className = ['imageOne','imageTwo','imageThree','imageFour','imageFive'], 
    index = 0;

function updateClassName() {
  this.className = className[++index % className.length];
}

document.getElementById('body').addEventListener("click", updateClassName);
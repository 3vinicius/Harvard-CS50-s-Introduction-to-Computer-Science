/* function redirections(event) {
  setTimeout(function() {
    fatchfor('pages/buy.html',document.querySelector("#root"))
    contentHeader = document.querySelector("#header")
    contentHeader = fatchfor('Components/Header/header.html', document.querySelector("#header"))
}, 2000) ; 
contentLogin = document.querySelector('#content-login')
contentLogin.innerHTML  = " "
contentLogin.innerHTML = `<svg xmlns="http://www.w3.org/2000/svg" fill="currentColor" class="bi bi-arrow-clockwise" viewBox="0 0 16 16">
<path fill-rule="evenodd" d="M8 3a5 5 0 1 0 4.546 2.914.5.5 0 0 1 .908-.417A6 6 0 1 1 8 2z"/>
<path d="M8 4.466V.534a.25.25 0 0 1 .41-.192l2.36 1.966c.12.1.12.284 0 .384L8.41 4.658A.25.25 0 0 1 8 4.466"/>
</svg>`
  event.preventDefault()
}
 */

function MyComponent(container) {
  this.container = container;
  this.render();
}

MyComponent.prototype.render = function () {
  this.container.innerHTML = fatchfor('../Components/Header/header.html', document.querySelector("#header"));
};

document.addEventListener('DOMContentLoaded', function () {
  const appContainer = document.getElementById('header');
  if (appContainer) {
    const myComponent = new MyComponent(appContainer);
  } else {
    console.error('Elemento com ID "app" não encontrado no DOM.');
  }
});


function fatchfor(path,refer){
  const contentRoot = refer;
  const caminhoCompleto = path; // Certifique-se de que este caminho está correto
fetch(caminhoCompleto)
    .then(response => {
        if (!response.ok) {
            throw new Error(`Erro ao carregar a página: ${response.status} ${response.statusText}`);
        }
        return response.text();
    })
    .then(html => {
        contentRoot.innerHTML = html;
    })
    .catch(error => console.error(error));
}

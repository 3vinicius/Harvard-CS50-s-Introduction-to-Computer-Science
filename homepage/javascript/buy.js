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


function MyComponent(container) {
  this.container = container;
  this.render();
}

MyComponent.prototype.render = function () {
  fatchfor('buy.html', document.querySelector("#root"));
  fatchfor('../Components/Header/header.html', document.querySelector("#header"));
};


document.addEventListener('DOMContentLoaded', function () {
  const appContainer = document.getElementById('root');
  if (appContainer) {
    const myComponent = new MyComponent(appContainer);

    
  } else {
    console.error('Elemento com ID "app" não encontrado no DOM.');
  }
});




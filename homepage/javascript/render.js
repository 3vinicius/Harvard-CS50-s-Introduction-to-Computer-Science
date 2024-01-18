function MyComponent(container) {
  this.container = container;
  this.render();
}

MyComponent.prototype.render = function () {
  this.container.innerHTML = fatchfor('pages/login.html', document.querySelector("#root"));
};


document.addEventListener('DOMContentLoaded', function () {
  const appContainer = document.getElementById('root');
  if (appContainer) {
    const myComponent = new MyComponent(appContainer);
  } else {
    console.error('Elemento com ID "app" não encontrado no DOM.');
  }
});

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


class Supervisor:
    def __init__(self, nome, limite_alerta):
        self.nome = nome
        self.limite_alerta = limite_alerta

    def get_limite_alerta(self):
        return self.limite_alerta

    def exibir_resumo(self):
        print(f"[Supervisor] {self.nome} | alerta >= {self.limite_alerta}")


def main():
    painel = Supervisor("ETA Central", 70)

    print(f"Nome direto: {painel.nome}")  # corrigido
    print(f"Limite: {painel.get_limite_alerta()}")  # corrigido
    painel.exibir_resumo()  # corrigido


if __name__ == "__main__":
    main()